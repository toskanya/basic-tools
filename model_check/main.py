from logic import *

rain = Symbol("rain") # It is raining
hagrid = Symbol("hagrid") # Harry visited Hagrid
dumbledore = Symbol("dumbledore") # Harry visited Dumbledore


# If is not raining, Harry visit Hagrid
# Harry visit Hagrid and Dumbledore
# Harry can't visit both
# Harry visit Dumbledore


sentence = And(
    Implication(Not(rain), hagrid),
    Or(hagrid, dumbledore),
    Not(And(hagrid, dumbledore)),
    dumbledore
)


print(sentence.string())
print(sentence.symbol())
print(model_check(sentence, rain))
print(model_check(sentence, hagrid))
print(model_check(sentence, dumbledore))