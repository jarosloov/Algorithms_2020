import requests
from bs4 import BeautifulSoup

res = requests.get('https://pogoda1.ru/katalog/sverdlovsk-oblast/temperatura-vody/')
soup = BeautifulSoup(res.content)
arr = []

for table in soup.select('.x-table > .x-row'):
	arr.append([])
	temperature = table.select_one('.x-cell-water-temp').get_text(strip=True)
	links = [a for a in table.select('.x-cell > .link')]
	name = links[0].text
	arr[-1].append(temperature)
	arr[-1].append(name)
   print("Температура рек: ")
	print(arr[-1])