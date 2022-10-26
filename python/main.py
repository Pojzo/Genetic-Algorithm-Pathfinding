import numpy as np


class VectorF:
    def __init__(
            self,
            x_: float,
            y_: float):

        self.x = x_
        self.y = y_

        def __add__(
                self,
                second_vector: VectorF) -> VectorF:

            return VectorF(self.x + second_vector.x, self.y + second_vector.y)


class WindowHandler:
    def __init__(self):
        pass

    def draw_point(
            self,
            pos_x: float,
            pos_y: float) -> None:
        ...


class Agent:
    current_move: int = 0
    all_dead: bool = False

    def __init__(
            self,
            num_moves: int,
            start_pos: tuple[int, int],
            vel_range: tuple[float, float]):

        self.moves = np.random.randint(*vel_range, num_moves)
        self.dead = False
        self.reached_goal = False
        self.fitness_score = 0

        self.pos = VectorF(*start_pos)
        self.vel = VectorF(0, 0)

    def move(self):
        if not self.dead:
            self.pos += self.vel

    def in_bounds(
            self,
            window_width: int,
            window_height: int) -> bool:

        return self.pos.x > 0 and self.pox.x < window_width and \
                self.pos.y > 0 and self.pos.y < window_height


# Simulation will simulate the genetic algorithm based on given hyperparameters
class Simulation:
    def __init__(
            self,
            window_handler_: WindowHandler,
            population_size_: int = 100,
            crossover_rate_: float = 0.5,
            mutation_rate_: float = 0.05,
            agent_vel_range: tuple[float, float] = (-5., -5.),
            num_moves_: int = 100,
            generations: int = 100):

        self.window_handler = window_handler_

        self.population_size = population_size_
        self.crossover_rate = crossover_rate_
        self.mutation_rate = mutation_rate_

        self.num_moves = num_moves_

        # initialize agents for the simulation
        self.create_agents(agent_vel_range)
        self.simulate(generations)

    def create_agents(
            self,
            agent_vel_range: tuple[float, float]) -> None:

        start_pos_x = self.window_handler.width / 2
        start_pos_y = self.window_handler.height - 20

        self.agents = [Agent(
            self.num_moves,
            (start_pos_x, start_pos_y),
            agent_vel_range)]

    def simulate(
            self,
            generations: int) -> None:

        for generation in range(generations):
            self.run_generation()

        def run_generation(self) -> None:
            Agent.current_move = 0
            while not Agent.all_dead or Agent.current_move < self.num_moves:
                self.show_agents()
                num_alive = 0
                for agent in self.agents:
                    if not agent.dead:
                        num_alive += 1
                        agent.move()
                        if not agent.in_bounds():
                            agent.dead = True

                if num_alive == 0:
                    Agent.all_dead = True

    def show_agents(self) -> None:
        for agent in self.agents:
            self.window_handler.draw_point(agent.pos.x, agent.pos.y)


if __name__ == "__main__":
    simulation = WindowHandler()
