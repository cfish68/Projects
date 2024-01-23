import csv
import os
import pandas as pd

#directory of all the files
path = "../files"
file_list = os.listdir(path)

#header for new file having all the websites from all the files
header = ['URL']

#structure to add all the websites row by row for the puropse of csv format
data = [[]]

for file_name in file_list:
    file_path = os.path.join(path, file_name)
    if ".xlsx" in file_name:
        df = pd.read_excel(file_path)
        lst = df.values
        for x in range(len(lst)):
            data.append([lst[x][0]])
    else:
        with open(file_path, 'r', encoding="utf-8") as file:
            csvReader = csv.reader(file)
            first = next(csvReader)
            for row in csvReader:
                data.append([row[0]])


w = open(os.path.join(path, "allURL1.txt"), "w", encoding="utf-8")
csvw = csv.writer(w)
csvw.writerow(header)
csvw.writerows(data)