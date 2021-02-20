#!/usr/bin/python3

def validUTF8(data):
	"""
	-----------------
	METHOD: validUTF8
	-----------------
	Description:
		Validates whether the data
		in a list is valid UTF-8.
	Args:
		data: list of ints
	Return:
		True if valid | False otherwise
	"""
	no_bytes = 0

	for num in data:
		if no_bytes == 0:
			mask = 1 << 7

			while num & mask:
				no_bytes += 1	# Counts the number of ones at the beginning
				mask >>= 1

			# According to the task reqs, no more than 4 bytes
			if no_bytes > 4:
				return False
		else:
			# Check if 1 and 0 are present
			# By pushing 6 numbers to the right, we're left with 2 digits
			# we need these two digits to be 1 and 0 which == 2
			if num >> 5 != 2:
				return False
		no_bytes -= 1
	return True