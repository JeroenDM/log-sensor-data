
from random import randint
from time import sleep
import datetime
import csv

bufferSize = 10
bufferArray = [0] * bufferSize

# initialize file
fieldnames = ['time', 'force1']
fileName = 'tireData.csv'

with open(fileName, 'w') as csvfile:
    fieldnames = ['time', 'force1']
    writer = csv.DictWriter(csvfile, fieldnames=fieldnames)
    writer.writeheader()

def writeBufferToFile():
    # Function to save current buffer to file
    with open(fileName, 'a') as csvfile:
        writer = csv.DictWriter(csvfile, fieldnames=fieldnames)
        writer.writerows(bufferArray)


while True:
    for i in range(bufferSize):
        timestamp = str(datetime.datetime.utcnow())
        value = randint(0,10)
        bufferArray[i] = {'time': timestamp , 'force1': str(value)}

    print(bufferArray)
    writeBufferToFile()

    # empty buffer, then there is an error when someting goes wrong
    # with filling up the array because 0 in not ok for DictWriter
    bufferArray = [0] * bufferSize

    sleep(1)
