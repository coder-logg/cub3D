# CUB3D  
  
Графический проект, использующий рейкастинг, по примеру игры 'Wolfenstein 3D'.  
![](./Screen_Shot.png)
----
## Основная часть
<table>
    <tr><td>Program name</td><td>cub3D</td></tr>
    <tr><td>Turn in files</td><td>All your files</td></tr>
    <tr><td>Makefile</td><td>all, clean, fclean, re, bonus</td></tr>
    <tr><td>Arguments</td><td>a map in format *.cub</td></tr>
    <tr><td>External functs.</td><td> <code>open</code>, <code>close</code>, <code>read</code>, <code>write</code>,
        <code>printf</code>, <code>malloc</code>, <code>free</code>, <code>perror</code>,
        <code>strerror</code>, <code>exit</code>
    <br>
    All functions of the <code>math</code>
    library (<code>-lm man man 3 math</code>) 
    <br>
    All functions of the <code>MinilibX</code>
        </td>
    </tr>
</table>

Ограничения следующие:
* Вы должны использовать `miniLibX`. Либо версия, доступная в операционной системе, либо из ее исходников.
  Если вы решите работать с исходниками, вам нужно будет применить те же правила для вашей библиотеки `libft`,
  что и написанные выше в части «Общие инструкции».
* Управление вашим окном должно оставаться плавным: переход к другому окну, сворачивание и т.д.
* Отображение различных текстур стен (выбор за вами), которые различаются в зависимости от того, с какой
  стороны обращена стена (север, юг, восток, запад).
  Ваша программа должна иметь возможность установить два разных цвета пола и потолка.
* Программа отображает изображение в окне и соблюдает следующие правила:
    * Клавиши со стрелками влево и вправо на клавиатуре должны позволять вам смотреть влево и вправо.
      прямо в лабиринте.
    * Клавиши W, A, S и D должны позволять перемещать точку обзора через
      лабиринт.
    * Нажатие ESC должно закрыть окно и полностью выйти из программы.
    * Щелчок по красному крестику на рамке окна должен закрыть окно и
      выйти из программы чисто.
    * Настоятельно рекомендуется использовать изображения `minilibX`.
* Ваша программа должна принимать в качестве первого аргумента файл описания сцены с расширением .cub.
    * Карта должна состоять только из 6 возможных символов: 0 для пустого места, 1 для стены и N, S, E или W
      для начальной позиции игрока и ориентации появления.
    * Вот пример простой карты:
  ```text
    111111 
    100101 
    101001
    1100N1
    111111
  ```
    * Карта должна быть закрыта/окружена стенами, в противном случае программа должна возвращать ошибку.
    * За исключением содержимого карты, каждый тип элемента может быть разделен одной или несколькими пустыми строками.
    * За исключением содержимого карты, которое всегда должно быть последним, каждый тип элемента может быть
      установлен в файле в любом порядке.
    * За исключением карты, каждый тип информации в элементе может быть разделен одним или несколькими пробелами.
    * Карта должна быть проанализирована так, как она выглядит в файле. Пробелы - это допустимая часть карты,
      которую вы можете решить. У вас должна быть возможность анализировать любую карту, если она соответствует правилам карты.
    * Информация о каждом элементе (кроме карты) - это сначала идентификатор типа (состоящий из одного или двух символов),
      за которым следует вся конкретная информация для каждого объекта в строгом порядке, например:
        * North texture:
          >NO ./path_to_the_north_texture

            - identifier: NO
            - path to the north texture
        * South texture:
          >SO ./path_to_the_south_texture

            - identifier: SO
            - path to the south texture
        * West texture:
          >WE ./path_to_the_west_texture

            - identifier: WE
            - path to the west texture
        * East texture:
          >EA ./path_to_the_east_texture

            - identifier: EA
            - path to the east texture
        * Floor color:
          >F 220,100,0

            - identifier: F
            - R,G,B colors in range [0,255]: 0, 255, 255
        * Ceilling color:
          >C 225,30,0

            - identifier: C
            - R,G,B colors in range [0,255]: 0, 255, 255
    * Пример обязательной части с минималистичной сценой .cub:
  ```text
    NO ./path_to_the_north_texture
    SO ./path_to_the_south_texture
    WE ./path_to_the_west_texture
    EA ./path_to_the_east_texture
    
    F 220,100,0
    C 225,30,0
    
            1111111111111111111111111
            1000000000110000000000001
            1011000001110000000000001
            1001000000000000000000001
    111111111011000001110000000000001
    100000000011000001110111111111111
    11110111111111011100000010001    
    11110111111111011101010010001    
    11000000110101011100000010001    
    10000000000000001100000010001    
    10000000000000001101010010001     
    11000001110101011111011110N0111  
    11110111 1110101 101111010001    
    11111111 1111111 111111111111    
   ```
    * Если в файле обнаружена какая-либо неправильная конфигурация, программа должна завершиться
      должным образом и вернуть «Error\n» с последующим явным сообщением об ошибке по вашему выбору.
## Бонусная часть
Список бонусов:
* Столкновения со стенами.
* Система миникарты.
* Двери, которые могут открываться и закрываться.
* Анимированный спрайт.
* Поверните точку обзора с помощью мыши.
