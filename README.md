Vinicius Nascimento et Luciana Adriao dos Santos
TP5 C++ Group 4
© 2024 ENSICAEN. All rights reserved.
This code is the intellectual property of ENSICAEN and is subject to the institution's terms and conditions.
Unauthorized reproduction, distribution, or use is strictly prohibited

### Remarque sur l'implémentation
Pendant le développement de ce projet, nous avons rencontré une difficulté concernant l'implémentation du **méthode `insert()`** (ajouter des éléments au début de la liste) et l'alternative possible, le **méthode `append()`** (ajouter des éléments à la fin de la liste). 
Comme nous n'avons pas implémenté `append()`, nous avons dû ajouter un **système de réversion des valeurs** à la fin de certaines fonctions, notamment dans `operator&` (intersection) et `image()`. Cela nous a permis d'assurer que la sortie respecte l'ordre attendu des éléments.
Cependant, il serait plus intéressant de choisir une des deux approches (`insert` ou `append`), ou bien d'implémenter les deux méthodes pour une meilleure flexibilité dans la gestion des données.

### Question finale : Pourquoi, dans l’avant-dernière instruction de `set_test.cpp`, utilise-t-on l’expression `singleton(string("void"))` et non pas `singleton("void")` ?

**Réponse :**
Nous utilisons `singleton(string("void"))` pour assurer la conversion explicite du type.
`"void"` est une chaîne de caractères littérale (`const char*`), et la fonction `singleton` attend un objet de type `std::string`.
Sans cette conversion, il y aurait une erreur de compilation, car le type `const char*` ne correspond pas directement à `std::string`.