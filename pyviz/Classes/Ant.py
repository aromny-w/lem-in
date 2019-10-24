class Ant:
	def __init__(self, number):
		self.num = number
		self.path = []
		self.current_position = None
		self.dest_position = None
		self.done = False
		self.movement = 0
		self.moving = False
		self.fromRoom = None
		self.toRoom = None
		self.started = False

	def add_room_to_path(self, room):
		self.path.append(room)

	def set_movement(self, nb):
		self.movement = nb
	
	def clear_movement(self):
		self.movement = 0
	
	def set_movin(self, bl):
		self.moving = bl

def create_ants(farm):
	ants = dict()
	for move in farm.move:
		for m in move:
			ant_num = m[0]
			ant_room = m[1]
			if not ant_num in ants:
				ants[ant_num] = Ant(ant_num)
				ants[ant_num].add_room_to_path(farm.start)
			ants[ant_num].add_room_to_path(ant_room)
	return ants
