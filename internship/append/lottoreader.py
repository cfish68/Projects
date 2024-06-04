import csv


file_path = "/Users/csfwn/Downloads/Lotto.csv"
file = open(file_path, 'r', encoding="utf-8")
csvReader = csv.reader(file)
nums = [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]

winingdouble =[]
next(csvReader)
for x in csvReader:
    if x[9] is not 0:
        winingdouble.append(x)