# import translation-master before executing
from translation import bing
f = open('srctext.txt', 'r')
file_contents = f.read()
b = str(file_contents)
x = input("Please enter the language to convert: ")
s = str(x)
print(bing(b, dst = s))
c=bing(b, dst = s)
d=str(c)
text_file = open('translatedtext.txt', 'w')
text_file.write(d)
text_file.close()