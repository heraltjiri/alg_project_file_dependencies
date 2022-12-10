# Spuštění

## Pomocí cmake

1. V kořenové složce projektu: ``cmake make . && make``
2. Spuštění pomocí: ``./ALG2_project VSTUPNI_SOUBOR.txt CISLO_ZMENENEHO_SOUBORU``

## Bez použití cmake

1. ``g++ main.cpp src/DataImporter.cpp src/DataImporter.h src/Graph.cpp src/Graph.h src/GraphNode.cpp src/GraphNode.h src/DependencyFinder.cpp src/DependencyFinder.h``
2. ``./a.out VSTUPNI_SOUBOR.txt CISLO_ZMENENEHO_SOUBORU``

# Zadání

V tomto zadání budeme řešit kompilaci zdrojových kódů rozsáhlého projektu. Takový projekt se obvykle skládá
z mnoha a mnoha souborů se zdrojovým kódem. U projektů implementovaných v jazyce C++ jde typicky o
cpp soubory a do nich vkládané hlavičkové soubory s příponou h. Představme si nyní, že jsme v roli vývojáře
pracujícího na projektu, provedli změnu v jednom ze souborů projektu. Pokud chceme projekt po této změně
zkompilovat, abychom získali aktuální verzi, máme dvě možnosti:
1. zkompilovat úplně všechny zdrojové kódy, což ale může být docela zdlouhavý proces, nebo
2. zkompilovat jen změněné části projektu.
   Pokud chceme kompilovat jen nezbytně nutné části projektu, čili jen některé zdrojové kódy, musíme znát závislosti mezi jednotlivými soubory se zdrojovým kódem. Závislost vznikne například pomocí direktivy #include.
   Tyto závislosti můžeme reprezentovat orientovaným grafem 𝐺, kde vrcholy grafu reprezentují jednotlivé soubory
   a hrany reprezentují závislosti souborů. Vede-li například orientovaná hrana z vrcholu 𝑢 do vrcholu 𝑣, znamená
   to, že soubor 𝑢 závisí na souboru 𝑣. Z tohoto grafu můžeme ale také určit, které soubory musíme znovu zkompilovat, když provedeme změnu v souboru reprezentovaném nějakým vrcholem 𝑤.
   Vaším úkolem je implementovat algoritmus, který pro zadaný graf závislostí mezi soubory 𝐺 a daný soubor
   (vrchol grafu) 𝑣 určí, které soubory jsou změnou souboru 𝑣 ovlivněny a musí se znovu zkompilovat.


