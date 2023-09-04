# example of a model: dict {
#   Q     : True
#   P     : False
#   P -> Q: True
#}

class Proposition():    
    def evaluate():
        '''evaluate the proposition'''
        raise ('Nothing to evalutate')
    
    def string():
        '''turn proposition into a string'''
        return ''
    
    def symbol():
        '''get all the symbols in the proposition'''
        return set()

    @classmethod
    def parenthesize(cls, ex):
        if not len(ex) or ex.isalpha():
            return ex
        else:
            return f"({ex})"

class Symbol(Proposition):
    def __init__(self, name):
        self.name = name
        
    def evaluate(self, model):
        try:
            return model[self.name]
        except KeyError:
            print(f'{self.name} is not in the model')
            
    def string(self):
        return self.name
    
    def symbol(self):
        return {self.name}
    
class Not(Proposition):
    def __init__(self, operand):
        self.operand = operand
        
    def evaluate(self, model):
        return not self.operand.evaluate(model)
    
    def string(self):
        return "¬" + Proposition.parenthesize(self.operand.string())
    
    def symbol(self):
        return self.operand.symbol()

class And(Proposition):
    def __init__(self, *conjuncts):
        self.conjuncts = list(conjuncts)
        
    def evaluate(self, model):
        return all([conjunct.evaluate(model) for conjunct in self.conjuncts])
    
    def string(self):
        return ''.join([f'{Proposition.parenthesize(conjunct.string())} ∧ ' for conjunct in self.conjuncts])[:-3]
    
    def symbol(self): 
        return set.union(*[conjunct.symbol() for conjunct in self.conjuncts])
    
class Or(Proposition):
    def __init__(self, *disjuncts):
        self.disjuncts = list(disjuncts)
        
    def evaluate(self, model):
        return any([disjunct.evaluate(model) for disjunct in self.disjuncts])
    
    def string(self):
        return ''.join([f'{Proposition.parenthesize(disjunct.string())} ∧ ' for disjunct in self.disjuncts])[:-3]
    
    def symbol(self): 
        return set.union(*[disjunct.symbol() for disjunct in self.disjuncts])
    
class Implication(Proposition):
    def __init__(self, antecedent, consequent):
        self.antecedent = antecedent
        self.consequent = consequent
        
    def evaluate(self, model):
        return not self.antecedent.evaluate(model) or self.consequent.evaluate(model)
    
    def string(self):
        return Proposition.parenthesize(self.antecedent.string()) + ' → ' + Proposition.parenthesize(self.consequent.string())
    
    def symbol(self): 
        return set.union(self.antecedent.symbol(), self.consequent.symbol())
    
class Biconditional(Proposition):
    def __init__(self, left, right):
        self.left = left
        self.right = right
        
    def evaluate(self, model):
        return (
            (not self.antecedent.evaluate(model) or self.consequent.evaluate(model)) and
            (self.antecedent.evaluate(model) or not self.consequent.evaluate(model))
        )
    def string(self):
        return Proposition.parenthesize(self.left.string()) + ' ↔ ' + Proposition.parenthesize(self.right.string())
    
    def symbol(self): 
        return set.union(self.left.symbol(), self.right.symbol())
    
def model_check(knowledge, query):
    
    def check_all(knowledge, query, symbols, model):

        # If there aren't any symbols left
        if not symbols:
            
            # Return True if both knowledge and query is True
            if knowledge.evaluate(model):
                return query.evaluate(model)
            return True
        
        # Recursively evaluate the models
        else:
            
            #Pop out a symbol
            remaining = symbols.copy()
            s = remaining.pop()
            
            model_true = model.copy()
            model_true[s] = True
            
            model_false = model.copy()
            model_false[s] = False
            
            return (check_all(knowledge, query, remaining, model_true) and 
                    check_all(knowledge, query, remaining, model_false))
        
    symbols = set.union(knowledge.symbol(), query.symbol())
    
    return check_all(knowledge, query, symbols, dict())