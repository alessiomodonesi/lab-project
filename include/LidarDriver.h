#ifndef LIDARDRIVER_H
#define LIDARDRIVER_H

#include <iostream>
#include <vector>

class LidarDriver
{

public:
    // constructor
    LidarDriver(double resolution = DEFAULT_RESOLUTION);

    // member functions
    void new_scan(std::vector<double> scan);                              // memorizza nel buffer una scansione
    std::vector<double> get_scan(void);                                   // fornisce in output la scansione più vecchia e la rimuove dal buffer
    void clear_buffer(void);                                              // elimina tutte le scansioni senza restituirle
    double get_distance(double angle);                                    // ritorna la lettura corrispondente a tale angolo
    double angular_resolution(void) const { return angular_resolution_; } // metodo get per la risoluzione, implementata in-class

private:
    double angular_resolution_;              // risoluzione angolare del sensore
    int position{-1};                        // posizione in cui è stata inserita l'ultima scansione
    int oldest_position{0};                  // posizione della scansione più vecchia
    std::vector<std::vector<double>> buffer; // buffer con vector bidimensionale

    static constexpr int BUFFER_DIM = 10;             // dimensione del buffer
    static constexpr int MAX_RANGE = 180;             // range massimo del sensore
    static constexpr double DEFAULT_RESOLUTION = 1.0; // risoluzione di default

    int update_position(int pos);     // restituisce correttamente la posizione successiva
    double round_angle(double angle); // trova l'angolo più vicino a quello passato come parametro in get_distance
};

// helper function
std::ostream &operator<<(std::ostream &out, const std::vector<double> &scan);

#endif // LIDARDRIVER_H