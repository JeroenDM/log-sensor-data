import serial
import datetime

# input buffer starts empty
ser = serial.Serial('COM3', 9600)

def writeToFile(line):
    text_file = open("Output.txt", "a")
    text_file.write(line)
    text_file.close()

header = "time,v1,v2,temperature\n"
writeToFile(header)

while True:
    # check if there is data available from the arduino
    if ser.in_waiting > 0:
        # readline wacht al op volledige lijn (tot en met \n)
        value =  ser.readline()
        print value
        if value:
            # add timestap
            timestamp = str(datetime.datetime.utcnow())
            writeToFile(timestamp + "," + value)
