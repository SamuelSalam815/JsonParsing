#include <memory>
#pragma once

struct JsonComponent
{
protected:
	// Child component has no ownership over its parent
	// i.e. parent out lives child
	// No need for shared pointer in this case
	std::weak_ptr<JsonComponent> parent;
	static void AdoptComponent(std::shared_ptr<JsonComponent> parent, std::shared_ptr<JsonComponent> child);
public:
	std::weak_ptr<JsonComponent> GetParent();
};

typedef std::shared_ptr<JsonComponent> SharedJsonComponent; // TODO : delete
