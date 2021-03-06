# marks-calculator

Programa yra skirta apskaičiuoti studento vidurkį/medianą, pagal jo įvestus/sugeneruotus pažymius.

## Veikimo principas

- Vartotojas pasitinka tokia žinutė:

```shell
g++ -std=c++0x -o main main.cpp readAndPrint.o calcFunctions.o randomGenerator.o
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
*                                                    *
*                                                    *
*                                                    *
*                 Pažymių skaičiuokė                 *
*                                                    *
*                                                    *
*                                                    *
//////////////////////////////////////////////////////

Pasirinkite norimą funkciją
Pažymių skaičiuoklė - 1
Vartotojo vadovas - 2
```

- Vartotojui leidziama pasirinkti ar pradeti pazymiu skaiciavima ar pamatytį vartotojo vadovą:

1. **JEI 1**

- Klausiama ar skaityti is failo ar suvesti duomenys ranka:
  a. **JEI 1**
- Nuskaitoma is failo
  b. **JEI 2**
- Vartotojas turi įvesti vardą pavardę pažymius egzamino pažymį.
- Jei duomenys buvo suvesti teisingai, programa automatiškai prades kito asmens duomenų įvedimą.
- Įvedus visus duomenys galima parasyti 'stop' arba 'baigti' ir programa nutrauks duomenų nuskaitymą.
- Vartotojas turi pasirinkti ar nori apskaičiuot vidurkį/medianą.

```shell
    Skaičiuoti vidurki - 1, mediana - 2
```

- Vartotojas turi pasirinkti ar saugoti i faila ar spausdinti ant ekrano.

```shell
    Įrašyti duomenys į failą?
    Taip - 1
    Ne - 2
```

- Programa apskaičiuoja vidurkį/medianą ir išveda duomenis:
  - Pavardę
  - Vardą
  - Galutinį pažymį (vidurkį/medianą).

2. **JEI 2**

- Vartotojui parodomas trumpas vartotojo vadovas.
- Perskaicius reikia parasyti 'exit'. Programa grazins i pagrindini ekrana.

:heavy_exclamation_mark: **Pažymius vartotojas turi įvesti per tarpą.**

:heavy_exclamation_mark: **Jei pazymis bus 0 programa sugeneruos atsitiktini skaiciu**

:heavy_exclamation_mark: **Paskutinis ivestas pazymis visada laikomas egzamino pazymiu**

:heavy*exclamation_mark: Galutinis vidurkis skaičiuojamas pagal formulę: \*\*galutinis = 0.4 * vidurkis + 0.6 \_ egzaminas\*\*.

## Įdiegimo instrukcija

- Atsisiųskite norimą programos versiją (rekomenduojama atsisiųsti naujausią versiją) iš [Releases](https://github.com/gameg0065/marks-calculator/releases) aplanko.
- Išarchyvuokite parsisiųstą failą.
- Komandinėje eilutėje įveskite:

```shell
    cd path_to_file
    make
    ./main
```

arba (Mac ar Linux)

```shell
    cd path_to_file
    bash run.sh
```

## Veikimo instrukcija

- Paleidus programą įveskite kintamuosius.

## Versijos

- [v0.1](https://github.com/gameg0065/marks-calculator/releases/tag/0.1) Pradinė sistemos versija.
- [v0.2](https://github.com/gameg0065/marks-calculator/releases/tag/0.2) Patobulinta sistemos versija leidzianti nuskaityti failus.
- [v0.3](https://github.com/gameg0065/marks-calculator/releases/tag/0.2) Klaidu metimas.
