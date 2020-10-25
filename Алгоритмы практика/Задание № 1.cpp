// [ размер матрицы ] матрица смежности 

// Пример: [4] 0101 1010 0101 1010

// vector<vector<bool>> 

#include <iostream>
#include <vector>

#include <istream>
#include <ostream>

#include <sstream>
#include <cassert>

#include <cctype>
#include <string_view>

using namespace std;

using Index = bool;
using Top = vector<Index>;
using Vector_Top = vector<Top>;

ostream& write_adjacency_matrix(ostream& out, Vector_Top const& adjacency_matrix) {
	out << '[' << adjacency_matrix.size() << ']' << endl;
	for (size_t i = 0; i < adjacency_matrix.size(); ++i) {
		for (size_t j = 0; j < adjacency_matrix.size(); ++j) {
			out << adjacency_matrix[i][j];
		}
		out << endl;
	}
	return out;
}

size_t write_test() {
	Vector_Top adjacency_matrix = { {0,1,0,1},{1,0,1,0},{0,1,0,1},{1,0,1,0} };
	ostringstream out;
	write_adjacency_matrix(out, adjacency_matrix);
	if (!out)
		return 1;
	if (out.str() == "[4]\n" "0101\n" "1010\n" "0101\n" "1010\n")
		return 0;
	return 2;
}

bool expect(istream& in, char prefix) {
	if (in.peek() == (unsigned char)prefix) {
		in.ignore();
		return true;
	}
	in.setstate(ios::failbit);
	return false;
}

bool expect(istream& in, string_view prefix) {
	while (!prefix.empty() && expect(in, prefix.front()))
		prefix.remove_prefix(1);
	return prefix.empty();
}

bool skipws_then_expect(istream& in, char prefix)
{
	assert(!isspace((unsigned char)prefix));
	if (char x; (in >> x) && (x == prefix))
		return true;
	in.setstate(ios::failbit);
	return false;
}

istream& read_adjacency_matrix(istream& in, Vector_Top& adjacency_matrix) 
{
	if (skipws_then_expect(in, '['))                                            // нашел [
	{										                                    
		adjacency_matrix.clear();										    	// чистим 
		size_t dimension;                                                       // читаем размерность
		in >> dimension;													    
		if (skipws_then_expect(in, ']'))                                        // нашел ]	
		{									                                								
			for (size_t i = 0;i < dimension; ++i)                               // заполням vector<vector<bool>>
			{							                                        
				Top line;
				char test;
				for (size_t j = 0; (j < dimension) && (in >> test); ++j)        // заполням vector<bool>
				{	
					if (test == '1')
						line.emplace_back(true);
					if (test == '0')
						line.emplace_back(false);
				}
				adjacency_matrix.emplace_back(line);						    // добавляем в vector<vector<bool>>: vector<bool>
			}
		}

	}
	else in.setstate(ios::failbit);
	return in;
}

size_t read_test() {
	Vector_Top adjacency_matrix;
	istringstream in("0101101001011010");
	if (read_adjacency_matrix(in, adjacency_matrix))
		return 1;
	in.clear();
	in.str("[4]0101101001011010");
	if (!read_adjacency_matrix(in, adjacency_matrix))
		return 2;
	if (adjacency_matrix != Vector_Top{ {0,1,0,1},{1,0,1,0},{0,1,0,1},{1,0,1,0} })
		return 3;
	return 0;
}

int main() {
	cout << write_test() << endl;
	cout << read_test() << endl;
	return 0;
}


