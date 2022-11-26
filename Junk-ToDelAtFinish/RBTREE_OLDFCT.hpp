void	transplant(node_type *oldNode, node_type *newNode) // 0 null
			{
				if (oldNode->parent == _header)
				{
					getRoot() = newNode; // null
					_header->parent = getRoot();

				}
				else if (oldNode == oldNode->parent->l_child)
				{

					oldNode->parent->l_child = newNode;
				}
				else{
					oldNode->parent->r_child = newNode;

				}
				
				if (newNode && newNode->parent)
					newNode->parent = oldNode->parent;
			}

void	eraseFix(node_type *node)
			{
				node_type *tmp;
				while ((node != getRoot()) && (node->colour == BLACK))
				{
					if ((node == node->parent->l_child))
					{
						tmp = node->parent->r_child;
						if ((tmp->colour == RED))
						{
							tmp->colour = BLACK;
							node->parent->colour = RED;
							rotateLeft(node->parent, getRoot());
							tmp = node->parent->r_child;
						}
						if (tmp->l_child->colour == BLACK && tmp->r_child->colour == BLACK)
						{
							tmp->colour = RED;
							node = node->parent;
						}
						else
						{
							if (tmp->r_child->colour == BLACK)
							{
								tmp->l_child->colour = BLACK;
								tmp->colour = RED;
								rotateRight(tmp, getRoot());
								tmp = node->parent->r_child;
							}
							tmp->colour = node->parent->colour;
							node->parent->colour = BLACK;
							tmp->r_child->colour = BLACK;
							rotateLeft(node->parent, getRoot());
							node = getRoot();
						}
					}
					else
					{
						tmp = node->parent->l_child;
						if (tmp->colour == RED)
						{
							tmp->colour = BLACK;
							node->parent->colour = RED;
							rotateRight(node->parent, getRoot());
							tmp = node->parent->l_child;
						}
						if (tmp->r_child->colour == BLACK && tmp->l_child->colour == BLACK)
						{
							tmp->colour = RED;
							node = node->parent;
						}
						else
						{
							if (tmp->l_child->colour == BLACK)
							{
								tmp->r_child->colour = BLACK;
								tmp->colour = RED;
								rotateLeft(tmp, getRoot());
								tmp = node->parent->l_child;
							}
							tmp->colour = node->parent->colour;
							node->parent->colour = BLACK;
							tmp->l_child->colour = BLACK;
							rotateRight(node->parent, getRoot());
							node = getRoot();
						}
					}
					tmp->colour = BLACK;
				}
			}

// void	erase(iterator z)
			// {
			// 	node_type	*nodeToDel = z.getNode(); // 0
			// 	node_type	*y = z.getNode(); // 0
			// 	// node_type	*newNode = z.getNode();
			// 	node_type	*tmp;
			// 	NodeColour 	yColour = y->colour; // b

			// 	if (!nodeToDel->l_child)
			// 	{
				
			// 		tmp = nodeToDel->r_child; // null
			// 		transplant(nodeToDel, nodeToDel->r_child); // 0, null
			// 	}
			// 	else if (!nodeToDel->r_child)
			// 	{
				
			// 		tmp = nodeToDel->l_child;
			// 		transplant(nodeToDel, nodeToDel->l_child);
			// 	}
			// 	else
			// 	{
			// 		y =  getMinOf(nodeToDel->r_child); // 4
										
			// 		yColour = y->colour;
			// 		tmp = y->r_child; // null
			// 		if (y->parent == nodeToDel)
			// 			tmp->parent = y;
			// 		else
			// 		{
			// 			transplant(y, y->r_child); // y now null
			// 			y->r_child = nodeToDel->r_child; // 5
			// 			y->r_child->parent = y; // null ?
			// 		}

			// 		transplant(nodeToDel, y);
			// 		y->l_child = nodeToDel->l_child;
			// 		y->l_child->parent = y;
			// 		y->colour = nodeToDel->colour;
			// 	}
			// 	if (yColour == BLACK)
			// 		eraseFix(tmp);
			// }