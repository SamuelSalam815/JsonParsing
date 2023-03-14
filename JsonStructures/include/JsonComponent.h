#include <memory>
#pragma once

struct JsonComponent
{
protected:
	// Child component has no ownership over its parent
	// i.e. parent out lives child
	// No need for shared pointer in this case
	JsonComponent* parent;
	void SetParent(std::shared_ptr<JsonComponent> child);
public :
	JsonComponent* GetParent();
};

typedef std::shared_ptr<JsonComponent> SharedJsonComponent;
