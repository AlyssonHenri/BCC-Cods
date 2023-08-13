from bs4 import BeautifulSoup
import requests

site = requests.get('https://darksouls.wiki.fextralife.com/Bosses')
soup = BeautifulSoup(site.text, "html.parser")

for i in soup.find_all('a', attrs={"class": "wiki_link wiki_tooltip"}):
    print(i.text)
