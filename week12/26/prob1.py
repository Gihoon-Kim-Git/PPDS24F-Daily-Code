def frequencySort(self, s: str) -> str:
	# Count the occurence on each character
	cnt = collections.Counter(s)
	
	# Build string
	res = []
	for k, v in cnt.most_common():
		res += [k] * v
	return "".join(res)