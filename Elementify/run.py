import argparse

AtomicNumber = []
i = 0
# flag is used so that first all the elements with more than 1 characters are matched as Ba D is a better choice than B A D
flag = False
# more is used to print their Atomic number along with symbols
more = False

elements = ["H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar", "K", "Ca", "Sc", "Ti", "V", "Cr",
 "Mn", "Fe", "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr", "Y", "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In",
  "Sn", "Sb", "Te", "I", "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd", "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Hf", "Ta", "W",
   "Re", "Os", "Ir", "Pt", "Au", "Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Ac", "Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es",
    "Fm", "Md", "No", "Lr", "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds", "Rg", "Cn", "Nh", "Fl", "Mc", "Lv", "Ts", "Og",
      "G", "L", "T", "Q", "D", "A", "E", "J", "M", "X", "R", "Z",]


# Elements "G", "L", "T", "Q", "D", "A", "E", "J", "M", "X", "R", "Z" are imaginary/fake and are needed to complete a name,
# at the time of writing the code I could find only 118 elements in periodic table :p

parser = argparse.ArgumentParser(description='Query for passing the string [--name string] and for printing with Atomic Number [--more] or [-m]')
parser.add_argument('--name', help='String to elementify',required=False)
parser.add_argument('-m', '--more', help='Print with Atomic Number',required=False, action='store_true')
args = parser.parse_args()

# print(len(elements))
if args.name:
	string = args.name.lower()
else:
	string = input("Enter a name you want to elementify: ").lower()

if string is '':
	string = "vibhor"


while(len(string)):
	if string.startswith(elements[i].lower()) and (len(elements[i]) == 2 or flag):
		string = string[len(elements[i]):]
		print (elements[i], end=' ')
		AtomicNumber.append(i+1)
		i = 0

	i = i + 1
	if i == len(elements):
		i = 0
		flag = True
		if string[0] == ' ':
	 		string = string[1:]
	 		flag = False
	 	 
print()
if args.more:
	print(AtomicNumber)	 	 