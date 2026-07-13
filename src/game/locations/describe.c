#include "treasure_venture.h"

void	describe_loc(t_man *man, const t_loc *loc)
{
	int	i;

	/* Display location name */
	if (!man->charas[0].current_loc->bool_is_indoors)
		printf("You are outside. ");
	else
		printf("You are in the %s. ", man->charas[0].current_loc->tags[0]);

	if (loc->bool_is_indoors)
		printf("%s ", loc->desc);
	else
		printf("The mansion in front of you gives you a bad feeling. Its "
			"main double doors don't look welcoming.");

	for (i = 0; i < NBR_ITEMS; ++i)
	{
		if (!loc->items[i])
			break;

		/*
			Only mention items which are not an access to an exit, such as a 
			door
		*/
		if (!loc->items[i]->access)
			printf("%s ", loc->items[i]->desc_look_around);
	}

	printf("\n\n");
	return;
}
