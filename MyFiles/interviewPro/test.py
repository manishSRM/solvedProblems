import random
import string
import argparse

class generatePassword:

	def __init__(self):
		self.length = 6
		self.characters = string.letters + string.digits

	def generate(self):
		pw = ''
		for i in xrange(self.length):
			index = random.randrange(len(self.characters))
			pw += self.characters[index]
		return pw

def main():
	parser = argparse.ArgumentParser(description="generate password for URL")
	parser.add_argument("url", help="it requires a password")
	args = parser.parse_args()
	obj = generatePassword()
	if args.url:
		newPassword = obj.generate()
		print newPassword

if __name__ == "__main__":
	main()
