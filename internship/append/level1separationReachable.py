import csv
import requests
import datetime
import ahocorasick
from itertools import islice
#file_path = "../files/allURL1.txt"
file_path = "../files/4 square test sample.txt"

file = open(file_path, 'r', encoding="utf-8")

csvReader = csv.reader(file)

header = next(csvReader)

#relevant Url add to this
properHeader = ["URL", "phone", "address", "contact"]
propercsv = []
#propercsv.append(properHeader)

#if no info append to this
noinfoHeader = ["URL", "date"]
noinfo = []
#noinfo.append(noinfoHeader)

#if domain for sale append to this.
urldomainforsaleHeader = ["URL", "date"]
urldomainforsale = []
#urldomainforsale.append(urldomainforsaleHeader)

#error case add to errorcsv
errorHeader = ["URL", "date", "typeError"]
errorcsv = []
#errorcsv.append(errorHeader)

#make an automata for an efficient search
automata = ahocorasick.Automaton()
for idx, substring in enumerate(["phone", "address", "contact", "domain for sale", "buy this domain"]):
    automata.add_word(substring, (idx, substring))
automata.make_automaton()


for row in islice(csvReader,20):
    try:
        r = requests.get(row[0])
        #todo: overhere check for site forwarding.


        phone = False
        address = False
        contact = False

        for end_index, (insert_order, original_value) in automata.iter(r.text):
            start_index = end_index - len(original_value) + 1
            match original_value:
                case "domain for sale":
                    urldomainforsale.append([row[0], str(datetime.datetime.now())])
                    break
                    print("domain for sale")
                case "buy this domain":
                    urldomainforsale.append([row[0], str(datetime.datetime.now())])
                    break
                    print("domain for sale")
                case "phone":
                    phone = True
                    print("Phone")
                case "address":
                    address = True
                    print("this is the address")
                case "contact":
                    contact = True
                    print("this should be explored further")
            #don't look any further if phone and address is true
            if(phone is True and address is True):
                break
            print(f"found {original_value}")
        if(phone == True or address == True or contact == True):
            propercsv.append([row[0], str(phone), str(address), str(contact)])
        else:
            noinfo.append([row[0], str(datetime.datetime.now())])
        
        print("works") 
    except requests.ConnectionError:
        errorcsv.append([row[0], str(datetime.datetime.now()), "Connection Error"])
        print("connection error")
    except requests.HTTPError:
        errorcsv.append([row[0], str(datetime.datetime.now()), "HTTP Error"])
        print("Http erorr")
    except requests.URLRequired:
        errorcsv.append([row[0], str(datetime.datetime.now()), "invalid URL Error"])
        print("a valid url is required")
    except requests.ReadTimeout:
        errorcsv.append([row[0], str(datetime.datetime.now()), "timeout Error"])
        print("readtimeout")
    except requests.ConnectTimeout:
        errorcsv.append([row[0], str(datetime.datetime.now()), "timeout Error"])
        print("connection timed out special case to retry with more time")
    except Exception as e:
        errorcsv.append([row[0], str(datetime.datetime.now()), "other Error"])
        print(e)


w = open("../files/test1/valid.txt", "w", encoding="utf-8")
csvw = csv.writer(w)
csvw.writerow(properHeader)
csvw.writerows(propercsv)

w = open("../files/test1/noinfo.txt", "w", encoding="utf-8")
csvw = csv.writer(w)
csvw.writerow(noinfoHeader)
csvw.writerows(noinfo)

w = open("../files/test1/forSale.txt", "w", encoding="utf-8")
csvw = csv.writer(w)
csvw.writerow(urldomainforsaleHeader)
csvw.writerows(urldomainforsale)

w = open("../files/test1/Error.txt", "w", encoding="utf-8")
csvw = csv.writer(w)
csvw.writerow(errorHeader)
csvw.writerows(errorcsv)