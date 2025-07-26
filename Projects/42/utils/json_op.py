import json

def save(name: str, data):
    """Save data (any JSON-serializable Python object) to a JSON file."""
    with open(name, "w") as f:
        json.dump(data, f, indent=4)  # indent=4 for pretty formatting

def load(name: str):
    """Load data from a JSON file and return the corresponding Python object."""
    with open(name, "r") as f:
        return json.load(f)