#include <iostream>
#include <vector>
#include <string>
#include <memory>

class Movies {
    private:
        std::string movie_name;
        std::string genre;
        float rating;
        std::vector<std::string> actors;

    public:
        Movies(std::string movie, std::string genre, float rating) : movie_name(movie), genre(genre), rating(rating) {};
        
        // Virtual Destructor
        virtual ~Movies() = default;

        virtual void PrintInfo() const {
            std::cout<< "Movie: " << movie_name << std::endl;
            std::cout<< "Genre: " << genre << std::endl;
            std::cout<< "Rating: " << rating << std::endl;
            std::cout<< "Actors: " << std::endl;
            for(const auto& actor : actors) {
                std::cout<< " - "<< actor<< std::endl;
            }
        }

        void AddActors(std::string name) {
            actors.push_back(name);
        }

};

int main() {
    // Movies* m = new Movies("The Lion King", "Animated/Drama", 9.0); // Raw Pointer - Heap
    Movies m("The Lion King", "Animated/Drama", 9.0); // Stack
    // auto m = std::make_unique<Movies>("The Lion King", "Animated/Drama", 9.0); // Smart Pointer
    // std::unique_ptr<Movies> m = std::make_unique<Movies>("The Lion King", "Animated/Drama", 9.0); // Smart Pointer with Explicit type

    m.AddActors("X");
    m.AddActors("Y");
    m.AddActors("Z");
    m.PrintInfo();

    Movies m2 = m;
    m2.PrintInfo();
    m2.movie_name = "Hello";
}