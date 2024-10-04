import serial
import time
import threading

# Replace this with your ESP32 Bluetooth address (find it in your computer's Bluetooth settings)
bt_address = "COM5"
# For Windows, it might look like: "COM4",
# For macOS: "/dev/tty.YOUR_DEVICE_NAME"

#Match this with the baud rate of the ESP32
BAUD_RATE = 9600

def esp32listener(esp32):
    while True:
        if esp32.in_waiting > 0:
            response = esp32.readline().decode('utf-8').strip()
            if response:
                print(f"\n[ESP32 Response]: {response}")

try:
    esp32 = serial.Serial(bt_address, BAUD_RATE)

    print("Connecting...",end="")
    while not esp32.is_open:
        print(".",end="")
        time.sleep(1)
    print("\nConnected to ESP32 Bluetooth")

    listener = threading.Thread(target=esp32listener, args=(esp32,))
    listener.daemon = True
    listener.start()

    print("Enter command (exit to leave): ")
    while True:
        cmd = input()
        if cmd == "exit":
            print("Exiting...")
            break
        esp32.write(cmd.encode())


except Exception as e:
    print(f"Error: {e}")

finally:
    if esp32.is_open:
        esp32.close()
        print("Connection closed")