from bs4 import BeautifulSoup
import requests


site = requests.get('')
soup = BeautifulSoup(site.text, "html.parser")

def gravar(nome):
    nome = clean(nome)
    f = open("personagens.txt", "a")
    f.writelines("('{}'),\n".format(nome))
    f.close()

def clean(text):
    cleaned = text.replace("'", "''").replace("(Dark Souls)", "").replace("[1]", "").replace("&nbsp", "").replace("?", "0")
    return cleaned.strip()

for i in soup.find_all('a', attrs={"class": "wiki_link"}):
    nome = i.text
    gravar(nome)
