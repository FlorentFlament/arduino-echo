import sys
import serial
import time

ser = serial.Serial('/dev/ttyUSB0', 1000000, stopbits=1, timeout=1)
time.sleep(2) # Wait for end of reset

print( ser.readline() )
while True:
    sys.stdout.write('> ')
    sys.stdout.flush()
    ser.write( str.encode(sys.stdin.readline()) )
    print( ser.readline() )
