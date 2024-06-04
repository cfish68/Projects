import requests
from bs4 import BeautifulSoup

def bestUniversityByCountry(country):
    # Write your code here\
    bestUniversity = ''
    rank = 0
    r = requests.get("https://jsonmock.hackerrank.com/api/universities")
    data = r.json()
    n = int(data['total_pages']) + 1
    for x in range(1, n):
        r = requests.get("https://jsonmock.hackerrank.com/api/universities?page=", x)
        data1 = r.json()
        for uni in data1['data']:
            c = uni['location']['country']
            if c == str(country):
                if uni['score'] > rank:
                    rank = uni['score']
                    bestUniversity = uni['university']
    return bestUniversity

print(bestUniversityByCountry('United States'))