# Wisielec

## Na czym polega program?  
Program polega na grze w wisielca. Jeżeli użytkownik gra sam, to wybiera kategorię, z której ma być wylosowane hasło. Jeśli natomiast chce zagrać z drugą osobą, to jedna z nich podaje hasło, a druga zgaduje. Gra trwa dopóki hasło nie zostanie odgadnięte lub graczowi nie skończą się życia (nie zostanie narysowana cała postać wisielca). Na koniec program wyświetla hasło oraz bazę graczy z danymi.

## Lista opcji do wyboru:  
- Przy wyborze kategorii, po podaniu litery innej niż te dozwolone (czyli inne niż: z, j, r), program zakończy się. (Jeśli natomiast poda się znaki, ciąg znaków lub liczby, program poprosi o poprawienie danych.)  
- Gdy wpisze się po raz drugi literę, która występuje w danym haśle, program uzna to jako błąd i dorysuje kolejną część wisielca.  
- Niedozwolone jest wpisywanie polskich znaków (wyświetla się błąd i nie można kontynuować gry).  
- Reszta rzeczy zawiera kontrolę poprawności.

## Struktura plików:  
- 3 pliki tekstowe zawierają słowa do losowania z danej kategorii. Typy danych to napisy.  
- Plik z bazą danych zapisuje w jednym wierszu nick, status z jaką użytkownik zakończył grę oraz liczbę wpisanych liter. Na koniec każdej gry, wyświetla się jego zawartość w konsoli.

## Diagram klas

![Diagram klas](diagram%20klas.png)
