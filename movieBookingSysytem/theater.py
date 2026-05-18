from screen import Screen


class Theater:
    id:str
    name:str
    city:str 
    screens:list[Screen]
    def __init__(self, id:str, name:str, city:str, screens:list[Screen]):
        self.id = id
        self.name = name
        self.city = city
        self.screens = screens
    
    