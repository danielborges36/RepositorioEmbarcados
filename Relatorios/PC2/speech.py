import speech_recognition as sr

rec = sr.Recognizer()

while True:
    with sr.Microphone() as s:
        rec.adjust_for_ambient_noise(s)
        print('Diga algo')
        
        audio = rec.listen(s)
        print('Voce disse: ' + rec.recognize_sphinx(audio) )

        #a = input('Continuar? ')
	#print(a)
        #if( a == 'n' ):
        #    break
