# 26766: Serca
#
# - 문제
# Informatycy to też ludzie, więc jak wszyscy potrzebują trochę miłości. Bajtek właśnie postanowił wyznać miłość pięknej Bajtolinie i w tym celu zamierza narysować jej N serduszek w ASCII art złożonych ze znaków małpy (@).
# Jedno serduszko wygląda następująco:
#  @@@   @@@
# @   @ @   @
# @    @    @
# @         @
#  @       @
#   @     @
#    @   @
#     @ @
#      @
# Bajtek chciałby, żeby serduszka były wypisane jedno pod drugim. Pomóż mu!
# Napisz program, który: wczyta liczbę N – liczbę serduszek, które Bajtek chce narysować Bajtolinie i wypisze na standardowe wyjście N serduszek w formacie opisanym powyżej.
#
# - 입력
# W pierwszym (jedynym) wierszu wejścia znajduje się jedna liczba całkowita dodatnia N, określająca liczbę serduszek do wypisania. Liczba ta będzie równa co najmniej 1 i co najwyżej 100 000.
#
# - 출력
# Twój program powinien wypisać na wyjście dokładnie N serduszek, jedno pod drugim.

s = ''' @@@   @@@ 
@   @ @   @
@    @    @
@         @
 @       @ 
  @     @  
   @   @   
    @ @    
     @     '''
for _ in range(int(input())):
    print(s)
