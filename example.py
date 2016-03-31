# example code to write csv file from
# https://docs.python.org/2/library/csv.html

import csv

data = [{'time': '2011' , 'force': str(10)},
        {'time': '2011' , 'force': str(10)},
        {'time': '2011' , 'force': str(10)},
        {'time': '2011' , 'force': str(10)}]

with open('names.csv', 'w') as csvfile:
    fieldnames = ['time', 'force']
    writer = csv.DictWriter(csvfile, fieldnames=fieldnames)

    writer.writeheader()
    writer.writerows(data)
