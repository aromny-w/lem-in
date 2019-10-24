import sys
import re

class Farm:
	def __init__(self):
		self.ants	= None
		self.start		= None
		self.end		= None
		self.rooms		= []
		self.links		= []
		self.move	  	= []
		self.nb_move	= 0

patterns = {
	'ants': re.compile('^\d+$'),
	'start': re.compile("^#{2}(start)$"),
	'end': re.compile("^#{2}(end)$"),
	'comment':re.compile("^#"),
	'room': re.compile("^([\d\w]+) \d+ \d+$"),
	'link': re.compile("^([\d\w]+)-([\d\w]+)$"),
	'move': re.compile("^(L[\d]+)-([\d\w]+)"),
}

def make_farm():
	farm = Farm()
	status = None

	for line in sys.stdin:
		if (status == 'start'):
			farm.start = line.split(' ')[0]
		elif (status == 'end'):
			farm.end = line.split(' ')[0]
		status = None

		if (patterns["ants"].search(line)):
			farm.ants = int(line)
		elif (patterns["start"].search(line)):
			status = "start"
		elif (patterns["end"].search(line)):
			status = "end"
		elif (patterns["comment"].search(line)):
			status = "comment"
		elif (patterns["room"].search(line) and line[0] != 'L'):
			line_split = line.split(" ")
			room_name = line_split[0]
			farm.rooms.append(room_name)
		elif (patterns["link"].search(line) and line[0] != 'L'):
			line_split = line.strip().split("-")
			farm.links.append(line_split)
		elif (patterns["move"].search(line)):
			final = []
			line_split = line.strip().split(" ")
			for element in line_split:
				line_split2 = element.split("-")
				ant = line_split2[0].strip('L')
				rooms = line_split2[1]
				pre_final = []
				pre_final.append(ant)
				pre_final.append(rooms)
				final.append(pre_final)
			farm.move.append(final)
			farm.nb_move += 1
	return (farm)
