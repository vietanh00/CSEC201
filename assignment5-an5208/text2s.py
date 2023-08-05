from gtts import gTTS
import os

my_text = "Text to be spoken"
language = "en"
output = gTTS(text=my_text, lang=language, slow=False)
#save this output to an mp3 file with name "output.mp3"
#output.save("output.mp3")
#os.system("start output.mp3")   #it's 'start' on windows, 'open' on linux

#read a text file into mp3 in read mode
text_file = open("test_tts.txt", "r")
my_text = text_file.read().replace("\n", " ") #tts wouldnt be able to "speak" line break
output = gTTS(text=my_text, lang=language, slow=False)
#save this output to an mp3 file with name "output.mp3"
output.save("output.mp3")
os.system("start output.mp3")

