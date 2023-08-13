from bs4 import BeautifulSoup
import requests
import re


site = requests.get('https://darksouls.wiki.fextralife.com/Places')
soup = BeautifulSoup(site.text, "html.parser")     

def gravar(i1,i2):
        f = open("inimigos.txt", "a")
        f.writelines("('{}', '{}''),\n".format(
            i1,i2))
        f.close()
                                   
for i in soup.find_all('a', attrs={"class": "wiki_link"}):
        link = i.get('href')
        endereco = "https://darksouls.wiki.fextralife.com" + link
        
        site2 = requests.get(endereco)
        soup2 = BeautifulSoup(site2.text, "html.parser")
        
        c = 0
        for tabela in soup2.find_all('div',attrs={'class':'col-sm-4 col-md-3 col-md-push-9'}):
            if c == 1:
                break
            
            boss = tabela.find_all('a')

            n = boss[1].text
            c=1
            print(n)
