#include <stdlib.h>
#include <string.h>

struct TreeNode {
	int	val;
	struct TreeNode *left;
	struct TreeNode *right;
};

#define STEP 8

static int **res, *col, *tmp, rescur, ressz, tmpcur, tmpsz;

static void addtmp(int v)
{
	if (tmpcur >= tmpsz) {
		tmpsz += STEP;
		tmp = realloc(tmp, tmpsz * sizeof(int));
	}
	tmp[tmpcur++] = v;
}

static void addres()
{
	if (!res) {
		ressz = STEP;
		res = malloc(ressz * sizeof(int *));
		col = malloc(ressz * sizeof(int));
	}
	if (rescur >= ressz) {
		ressz += STEP;
		res = realloc(res, ressz * sizeof(int *));
		col = realloc(col, ressz * sizeof(int));
	}
	res[rescur] = malloc(tmpcur * sizeof(int));
	memcpy(res[rescur], tmp, tmpcur * sizeof(int));
	col[rescur] = tmpcur;
	rescur++;
}

static void do_pathsum(struct TreeNode *root, int sum, int cur)
{
	if (!root)
		return;

	cur += root->val;
	addtmp(root->val);
	if (!root->left && !root->right) {
		if (cur == sum)
			addres();
		tmpcur--;
		return;
	}
	do_pathsum(root->left, sum, cur);
	do_pathsum(root->right, sum, cur);
	tmpcur--;
}

int **pathSum(struct TreeNode *root, int sum, int **columnSizes,
		int *returnSize)
{
	res = 0;
	col = 0;
	rescur = 0;
	tmpcur = 0;
	tmpsz = STEP;
	tmp = malloc(tmpsz * sizeof(int));
	do_pathsum(root, sum, 0);
	*columnSizes = col;
	*returnSize = rescur;
	free(tmp);
	return(res);
}

int main(void)
{
}
