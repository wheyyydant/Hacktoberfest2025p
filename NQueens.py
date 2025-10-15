# Implementation of the N-Queens problem using backtracking
def solve_n_queens(n:int):
	"""
	Solve the N-Queens problem and return all distinct solutions.
	Each solution contains a list of integers where the index represents the row and the value at that index represents the column of the queen in that row.
	:param n: Size of the chessboard (n x n) and number of queens
	:return: List of solutions, where each solution is represented as a list of column indices
	"""
	def is_not_under_attack(row:int, col:int):
		"""
		Check if placing a queen at (row, col) is safe from attacks by previously placed queens.
		:param row: Current row to place the queen
		:param col: Current column to place the queen
		:return: True if safe, False otherwise
		"""
		for prev_row in range(row):
			if (board[prev_row] == col or
				board[prev_row] - prev_row == col - row or
				board[prev_row] + prev_row == col + row):
				return False
		return True

	def place_queen(row:int):
		"""
		Place queens on the board using backtracking.
		:param row: Current row to place the queen
		"""
		if row == n:
			result.append(board[:])
			return
		for col in range(n):
			if is_not_under_attack(row, col):
				board[row] = col
				place_queen(row + 1)
				board[row] = -1  # Reset the row

	result = []
	board = [-1] * n
	place_queen(0)
	return result

def print_board(board):
	"""
	Print the chessboard with queens placed.
	:param board: List of column indices where queens are placed
	"""
	n = len(board)
	for row in range(n):
		line = ['.'] * n
		if board[row] != -1:
			line[board[row]] = 'Q'
		print(' '.join(line))
	print()

# Example usage:
if __name__ == "__main__":
	n = 4
	solutions = solve_n_queens(n)
	print(f"Found {len(solutions)} solutions for {n}-Queens problem.")
	for solution in solutions:
		print_board(solution)