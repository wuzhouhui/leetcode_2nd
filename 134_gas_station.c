int canCompleteCircuit(int *gas, int gasSize, int *cost, int costSize)
{
	int	i, total, index, sum;

	if (!gasSize)
		return(-1);

	total = sum = 0;
	for (i = 0; i < gasSize; i++) {
		sum += gas[i] - cost[i];
		total += sum;
		if (sum < 0) {
			sum = 0;
			index = i;
		}
	}
	if (total < 0)
		return(-1);
	else
		return(++index % gasSize);
}

int main(void)
{
}
