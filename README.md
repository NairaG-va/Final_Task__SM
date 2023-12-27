# Метод стрельбы

Сводим нашу задачу к задаче следующего вида:  
$y' = z$   
$z' = -\sqrt{x}z - x^2y - x$  
$y(0) = 2$  
$y(1) = 2$ 

## Описание работы программы
Вводим с консоли шаг интервала $m$, в котором будем искать значение $ksi$, и границы этого интервала - $left, right$. Для обработки исключений применяем конструкцию try...catch. 
Задаем значения $n$ и $h$, где $h$ - шаг, с которым мы пробегаем отрезок $[0,1]$. Создаем два вектора $y, z$. 
Задаем произвольные значения переменным $ksi$ и $min$ ($min$ требуется в дальнейшем для нахождение минимального выстрела, т.е значения, возвращаемого функцией shoot, описанной в shoot.cpp). 
С помощью цикла for находим нужное нам значение $ksi$, при котором значение, возвращаемое функцией shoot, по модулю будет минимально.
Выводим $ksi$ и соответствующее значение функции shoot.   

Далее делаем проверку: если значение, возвращаемое функцией shoot, по модулю больше единицы, то сообщаем о неправильно
подобранных границах интервала или шаге. В противном случае выводим на экран все значения $x[i]$ и $y[i]$ и запускаем тест. В тесте создаем вектор $testVec$ и записываем в него уже посчитанные в 
точках значения. Затем в тесте сравниваем элементы векторов $testVec$ и $res$, в который мы передаем полученные с помощью нашего метода значения. Если $|res[i] - testVec[i]| < 0.01$, 
то тест считаем пройденным. 

В самой функции shoot мы решаем задачу Коши методом Эйлера и возвращаем значение $y(1) - 2$.


Хорошие значения $m = 0.001$, $ksi = 0.368$. В таком случае значение, возвращаемое функцией shoot, равно $5.70463e-05$.
