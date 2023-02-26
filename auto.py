import pyautogui
import keyboard

print("Press and hold the p button!")
times_pressed = 0

while True:
    if keyboard.is_pressed('p'):
        # Get the current position of the mouse
        x, y = pyautogui.position()

        # Press the left mouse button at the current position
        pyautogui.mouseDown(x, y)

        # Release the left mouse button at the same position
        pyautogui.mouseUp(x, y)
        times_pressed += 1

        # Print a message every 100 left mouse button presses
        if times_pressed % 100 == 0:
            print("Pressed Left Mouse Button: ", times_pressed, " times!")