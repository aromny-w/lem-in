import pygame
from pygame.locals import *
import math

STEPS_NEED = 10

class Visualize:
	def __init__(self, farm, ants, G, pos):
		self.width = None
		self.height = False
		self.farm = farm
		self.ants = ants
		self.G = G
		self.pos = pos
		self.background = None
		self.rooms_surface = None
		self.info_object = None
		self.rooms = {}
		self.step_que = []
		self.step_done = False

	def count_background(self):
		self.background_width = int(self.width * 0.9)
		self.background_height = int(self.height * 0.9)
		self.background = pygame.Surface((self.background_width, self.background_height))
		self.background.fill((74, 42, 106))
		self.rooms_surface = pygame.Surface((int(self.width * 0.9), int(self.height * 0.9)), pygame.SRCALPHA, 32)
		self.rooms_surface.convert_alpha
		for room in self.farm.rooms:
			w = self.rooms_surface.get_width()
			h = self.rooms_surface.get_height()
			csx = int(w * 0.05 + (w - w * 0.1) / 2 + (self.pos[room][0] * (w) / 2))
			csy = int(h * 0.05 + (h - h * 0.1) / 2 + (self.pos[room][1] * (h) / 2))
			color = (255, 0, 0)
			if (room == self.farm.start):
				color = (0, 0, 255)
			if (room == self.farm.end):
				color = (0, 255, 0)

			pygame.draw.circle(self.rooms_surface, color, (csx, csy), 5)
			if (room not in self.rooms):
				self.rooms[room] = {}
				self.rooms[room]['csx'] = None
				self.rooms[room]['csy'] = None
				self.rooms[room]['cx'] = None
				self.rooms[room]['cy'] = None
			self.rooms[room]['csx'] = csx
			self.rooms[room]['csy'] = csy
			self.rooms[room]['cx'] = self.width * 0.05 + csx - 5/2
			self.rooms[room]['cy'] = self.height * 0.05 + csy - 5/2

		for link, value in self.farm.links:
			if (link in self.rooms and value in self.rooms):
				pygame.draw.line(self.rooms_surface, (255, 255, 0), (
					self.rooms[link]['csx'],
					self.rooms[link]['csy']
				), (
					self.rooms[value]['csx'],
					self.rooms[value]['csy']))

	def init(self):
		pygame.init()
		self.info_object = pygame.display.Info()
		self.width = int(self.info_object.current_w * 0.8)
		self.height = int(self.info_object.current_h * 0.8)
		pygame.display.set_caption('The Lem-in visuelizer | Visu-Hex')
		self.run = True
		self.screen = pygame.display.set_mode((self.width, self.height), HWSURFACE|DOUBLEBUF|RESIZABLE)
		self.count_background()
		self.step_done = True
		self.main_cycle()
	
	def activate_ants(self):
		if self.step_done:
			self.step_done = False
			if len(self.farm.move) > 0:
				self.step_que.append(self.farm.move.pop(0))
				pygame.time.delay(100)

	def main_cycle(self):
		while (self.run):
			self.handle_events()
			self.render()
			self.activate_ants()
			pygame.time.delay(100)
		self.destroy()

	def draw_ant(self, x, y):
		pygame.draw.rect(self.screen, (0, 0, 0), (x, y, 5, 5))

	def count_x_y(self, x1, y1, x2, y2, movement):
		dx = x2 - x1
		dy = y2 - y1
		
		leng = math.sqrt(dx*dx + dy*dy)
		dirx = dx/leng
		diry = dy/leng

		expectedDist = leng / STEPS_NEED *  movement
		
		dirx *= expectedDist
		diry *= expectedDist
		x = dirx + x1
		y = diry + y1
		return int(x), int(y)

	def render_ants(self):
		for steps in self.step_que:
			for ant, room in steps:
				if self.ants[ant].moving == False:
					print(self.ants[ant].path)
					if self.ants[ant].path[0] == self.farm.start:
						self.ants[ant].path.pop(0)
						self.draw_ant(self.rooms[self.farm.start]['cx'], self.rooms[self.farm.start]['cy'])
						self.ants[ant].moving = True
						self.ants[ant].movement = 0
						self.ants[ant].done = False
						self.ants[ant].fromRoom = self.farm.start
						self.ants[ant].toRoom = self.ants[ant].path[0]
					elif self.ants[ant].path[0] != self.farm.start:
						self.ants[ant].moving = True
						self.ants[ant].movement = 0
						self.ants[ant].done = False
						self.ants[ant].toRoom = self.ants[ant].path[0]
				else:
					if self.ants[ant].movement == STEPS_NEED:
						self.ants[ant].fromRoom = self.ants[ant].toRoom
						self.ants[ant].moving = False
						self.step_que = []
						self.step_done = True
						self.ants[ant].path.pop(0)
					elif self.ants[ant].moving:
						self.ants[ant].movement += 1
						fromRoom = self.rooms[self.ants[ant].fromRoom]
						toRoom = self.rooms[self.ants[ant].toRoom]
						x, y = self.count_x_y(fromRoom['cx'], fromRoom['cy'], toRoom['cx'], toRoom['cy'], self.ants[ant].movement)
						self.draw_ant(x, y)

	def render(self):
		self.screen.blit(self.background, (self.width * 0.05, self.height * 0.05))
		self.screen.blit(self.rooms_surface, (self.width * 0.05, self.height * 0.05))
		self.render_ants()
		pygame.display.update()

	def handle_events(self):
		for event in pygame.event.get():
			if event.type == pygame.QUIT:
				self.quit()
			elif event.type == VIDEORESIZE:
				self.width = event.dict['size'][0]
				self.height = event.dict['size'][1]
				self.screen = pygame.display.set_mode((self.width, self.height), HWSURFACE|DOUBLEBUF|RESIZABLE)
				self.count_background()

	def quit(self):
		self.run = False

	def destroy(self):
		pygame.quit
