
/*
void actualizar(std::vector<AStarNodo*>& n)
{
	std::make_heap(n.begin(),n.end(),menor);//hago uso de monticulo
    std::sort_heap(n.begin(),n.end(),menor);
}
*/
void push(std::vector<AStarNode*>& v, AStarNode* current)
{
	v.push_back(current);
	std::make_heap(v.begin(),v.end(),menor);//hago uso de monticulo
    std::sort_heap(v.begin(),v.end(),menor);
}

AStarNode* pop(std::vector<AStarNode*>& o, std::vector<AStarNode*>& c)
{
    AStarNode* a = o.back();
    o.pop_back();
    c.push_back(a);
    std::make_heap(o.begin(),o.end(),menor);//hago uso de monticulo
    std::sort_heap(o.begin(),o.end(),menor);
    return a;  
}

void DEF_LIB_EXPORTED calculatePath(AStarNode* originNode, AStarNode* targetNode
                   , int cellsWidth, int cellsHeight, float mapWidth, float mapHeight
                   , float** additionalCost, std::list<Vector3> &path) {
                   	
    std::vector<AStarNode*> o;
    std::vector<AStarNode*> c;
    AStarNode* actual = originNode;
    
    current->G = 0;
    current->H = _sdistance(current->position, targetNode->position);
    
    current->F = current->H + current->G;
    
    push(o, actual);
    
    bool encontrado = false;
    
    while(encontrado == false && o.size() > 0)
    {
    	actual = pop(o,c);
    	
    	if(actual == targetNode)
    	{
    		encontrado = true;
		}else
		{
			for(std::list<AStarNode*>::iterator j = actual->adjacents.begin(); j != actual->adjacents.end();++j)
            {
            	if(search(c,(*j)) == false)//para saber que es distinto de close
                {
                	if(search(o,(*j)) == false)//para saber que es distinesto de open
                    {
                    	(*j)->parent = actual;
                        (*j)->G = actual->G + _distance(actual->position, (*j)->position);//duda distance
                        (*j)->H = _sdistance((*j)->position, targetNode->position)//duda con estimated distance
                        (*j)->F = (*j)->G + (*j)->H;
                        push(o,(*j));
					}else{
						float d = _distance((*i)->position, actual->position);
						if((*j)->G > actual->G + d)
                        {
                            (*j)->parent = actual;
                            (*j)->G = actual->G + d;
                            (*j)->F = (*j)->G + (*j)->H;
                            actualizar(o);
                        }
					}
				}
			}
		}
	}
    
    AStarNode* final = targetNode;
    while(final != originNode)
    {
    	path.push_front(final->position);
        final = final->parent;
    }

	path.push_front(final->position);
}


