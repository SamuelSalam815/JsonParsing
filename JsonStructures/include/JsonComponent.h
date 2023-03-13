#include <memory>
#pragma once

struct JsonComponent : public std::enable_shared_from_this< JsonComponent >
{
protected:
	std::weak_ptr<JsonComponent> parent;
	static void SetParent
	(
		std::shared_ptr<JsonComponent> parent,
		std::shared_ptr<JsonComponent> child
	);
public :
	std::weak_ptr<JsonComponent> GetParent();
};

typedef std::shared_ptr<JsonComponent> SharedJsonComponent;
