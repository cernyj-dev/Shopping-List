# Informace o úloze #

Úkolem je vyvinout program, který optimalizuje nákupy v supermarketech a zkracuje čas strávený hledáním položek na nákupních seznamech. Nákupy v supermarketech jsou pro některé lidi příjemnou aktivitou (shopaholic), zatímco pro jiné představují noční můru (shopafobic). Zatímco shopaholici si užívají procházení regály a zkoumání, co si koupit, shopafobici se raději drží přesně stanoveného seznamu a snaží se minimalizovat čas strávený v obchodě. Cílem je uspořádat nákupní seznam tak, aby se minimalizovalo bloudění supermarketem a zamezilo se opakovanému chození mezi regály.

Specifikace: Program dostane jako vstup dvě věci: rozmístění zboží v regálech a nákupní seznam. Regály jsou očíslovány od 0 do N a každý regál obsahuje seznam položek (např. "tomato", "milk", "cheese"). Nákupní seznam může obsahovat položky jako "tomato", ale v obchodě mohou být dostupné varianty jako "red tomato", "yellow tomato" nebo "cherry tomatoes". Program bude hledat položky na regálech a pokud nenajde přesnou shodu, pokusí se najít položku, jejíž název obsahuje požadovaný název jako podřetězec (při porovnávání nebude rozlišovat velká a malá písmena). Pokud položka není k dispozici v obchodě, bude přesunuta na konec seznamu.

Po zpracování seznamu program výstupně upraví seznam položek, a to tak, že:

Seřadí položky podle regálů (s rostoucím číslem regálu).

Pokud je položka ve stejném regálu vícekrát, zachová původní pořadí.

Pokud je položka k dispozici na více regálech, bude vybrána první možnost.

Pokud není položka v obchodě k dispozici, bude umístěna na konec seznamu.

Vstupní validace: Program musí také validovat vstupní data a detekovat chyby. Za chybu se považuje:

Chybějící číslo regálu při zadávání zboží (regál 0 musí být první).

Neplatné číslo regálu nebo nesprávná sekvence čísel (regály musí být seřazeny 0, 1, 2, ...).

Chybějící prázdná řádka za seznamem zboží.

Účel programu: Cílem je nejen minimalizovat čas strávený hledáním zboží v supermarketu, ale také efektivně uspořádat nákupní seznam, což může výrazně zvýšit pohodlí a zrychlit nákupní proces. Program by měl zvládnout základní testy s jednoduchým algoritmem, ale pro bonus je třeba implementovat efektivnější algoritmus pro zpracování dlouhých nákupních seznamů.

Tento program může být užitečný nejen pro běžné nákupy, ale i pro optimalizaci v obchodních aplikacích, kde je důležitá efektivita a rychlost při hledání položek na regálech.
