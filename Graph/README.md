### VIRTUAL keyword use

```
class Graph {
	virtual void getdata()
}

class Subgraph : Graph {
	void getdata()
}

Graph o;
Subgraph z;

o = z;

o.getdata(); //-> calls the subgraph function because of the "virtual"
```
