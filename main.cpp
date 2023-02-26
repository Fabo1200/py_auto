#include <iostream>
#include <Windows.h>

int main()
{
    // Aufforderung zur Eingabe der Verzoegerungszeit in Millisekunden
    int delay_ms;
    std::cout << "Geben Sie die Verzoegerungszeit in Millisekunden ein (muss groesser als 25 sein, aber 100 funktioniert meistens): ";
    std::cin >> delay_ms;
        if (delay_ms < 25) {
            std::cout << "Die Verzoegerungszeit muss groeßer als 25 Millisekunden sein. Bitte geben Sie eine groeßere Verzoegerungszeit ein!" << std::endl;
            std::cin >> delay_ms;
        }
    std::cout << "Druecken und halten Sie die Taste 'P'!" << std::endl;
    int times_pressed = 0;
    std::cout << "Sie koennen das Programm beenden, indem Sie gleichzeitig 'STRG + C' druecken!" << std::endl;
    int loop_count = 0;
    while (true)
    {
        if (GetAsyncKeyState('P') & 0x8000)
        {
            // Aktuelle Mausposition ermitteln
            POINT p;
            GetCursorPos(&p);
            int x = p.x;
            int y = p.y;
            // Linke Maustaste an der aktuellen Position druecken
            INPUT input = { 0 };
            input.type = INPUT_MOUSE;
            input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
            input.mi.dx = x;
            input.mi.dy = y;
            SendInput(1, &input, sizeof(input));
            // Mit der angepassten Verzoegerungszeit warten
            int adjusted_delay_ms = delay_ms;
            if (loop_count % 2 == 0)
                adjusted_delay_ms += 5;
            else 
                adjusted_delay_ms -= 5;
            
            Sleep(adjusted_delay_ms);
            // Linke Maustaste an der gleichen Position loslassen
            input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
            SendInput(1, &input, sizeof(input));
            times_pressed += 1;
            // Alle 100 Linksklicks eine Meldung ausgeben
            if (times_pressed % 100 == 0)
            {
                std::cout << "Linke Maustaste " << times_pressed << " Mal gedrueckt!" << std::endl;
            }
            // Zähler fuer die nächste Schleifendurchfuehrung inkrementieren
            loop_count++;
        }
    }
    return 0;
}