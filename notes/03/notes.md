# Графи. Дървета. Обхождания на графи.

- Дефиниции за краен ориентиран (мулти)граф и краен неориентиран (мулти)граф.

  + Краен ориентиран мултиграф:
    - Нека V = {v1, v2,..., vn} е крайно множество, елементите на което наричаме
    върхове, а Е = {e1, e2,..., en} е крайно множество, елементите на което
    наричаме ребра. Функцията fG: E -> V x V, съпоставяща на всяко ребро двойка
    върхове, **наричаме краен ориентиран мултиграф**. Казваме още, че е зададен
    краен ориентиран мултиграф G с върхове V, ребра Е и свързваще фунцкия fG и
    го означаваме с G(V, E, fG).
    - Нека G(V, E, fG) е краен ориентиран мултиграф и функцията fG е еднозначна,
    т.е. f(ei) ≠ f(ej),i ≠ j.Тогава G(V, E, fG) **наричаме краен  ориентиранграф**. Означаваме го с G(V, E).
  + Краен неориентиран мултиграф:
    - Нека G(V, E) е краен ориентиран граф, такъв че релацията E ⊆ V x V е
    *рефлексивна и симетрична*. В такъв случай G(V, E) **наричаме краен
    неориентиран граф или просто граф**. Ако вместо множеството E ⊆ V x V вземем
    мултимножеството от елементи на V x V, графът се нарича **краен неориентиран
    мултиграф**.


- Дефиниции за път (цикъл) в ориентиран и неориентиран мултиграф.
  + Нека G(V, E, fG) е ориентиран мултиграф. Редицата от редуваще се върхове и
  ребра на G:  vi0, el1, vi1, el2, vi2,...,vi(k-1), elk, vik, в която
  fG(elj) = (vi(j-1), vij), j = 1, 2,...,k, **наричаме маршрут в G от vi0 до
  vik**. Ако vik = vi0, тогава редицата vi0, el1, vi1, el2, vi2,...,vi(k-1),
  elk, vik **наричаме контур**.
  + Нека G(V, E) е мултиграф. Редицата от редуваще се върхове и
  ребра на G:  vi0, el1, vi1, el2, vi2,...,vi(k-1), elk, vik, в която
  elj = (vi(j-1), vij), j=1, 2,...,k и vi(j-1) ≠ vi(j+1), j=1,2,..., k-1,
  **наричаме път в G между vi0 и vik**. Всеки връх vi на мултиграф е тривиален
  път с дължина 0.  Ако vik = vi0, тогава редицата vi0, el1, vi1, el2, vi2,...,
  vi(k-1), elk, vik **наричаме цикъл**.


- Свързаност и свързани компоненти на граф.

  За всеки краен неориентиран граф G(V, E) дефинираме релацията PG ⊆V ×V , така
  (vi ,vj ) ∈ PG тогава и само тогава когато съществува път в G от vi до vj.

  + Върховете от всеки клас на еквивалентност V′ ⊆ V на релацията PG индуцират
  в G(V, E) по един подграф, който **наричаме свързана компонента** на G. Графът
  G(V ,E) **се нарича свързан**, ако ∀ vi, vj ∈ V, ∃ път в G от vi до vj, т.е. G
  има точно една свързана компонента.


- Дефиниция на дърво и кореново дърво.
- Доказателство, че всяко кореново дърво е дърво и |V|=|E|+1.
- Покриващо дърво на граф.
- Обхождане на граф в ширина и дълбочина.
- Ойлерови обхождания на мултиграф.
- Теореми за съществуване на Ойлеров цикъл (с доказателство) и Ойлеров път.
