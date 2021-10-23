all: principal

# directorios
HDIR    = include
CPPDIR  = src
ODIR    = obj

OBJETOS = CantidadTotalJugadores FechaHoraSistema \
Categoria ControladorPartida ControladorUsuario ControladorVideojuego Desarrollador\
DtAbandonarPartidaMultijugador DtCategoria DtComentario DtCosto DtFechaHora\
DtGenero DtInfoBasicaPartidaIndividual DtInfoBasicaVideojuego DtInfoCategoria DtInfoEstadistica DtInfoSusc \
DtInfoVideojuego \
DtJugador DtPartida DtPartidaIndividual DtPartidaMultijugador DtPlataforma DtValorEstadistica DtVideojuego\
Estadistica Fabrica Genero HistorialSuscripciones Jugador JugadorUnido Partida PartidaIndividual\
PartidaMultijugador Plataforma Puntaje Suscripcion SuscripcionTemporal SuscripcionVitalicia\
TotalHorasJugadas Usuario Videojuego \

# compilador
CC = g++

# cadena de archivos, con directorio y extensión
HS   = $(OBJETOS:%=$(HDIR)/%.h)
CPPS = $(OBJETOS:%=$(CPPDIR)/%.$(cpp))
OS   = $(OBJETOS:%=$(ODIR)/%.o)

PRINCIPAL=principal
EJECUTABLE=principal

LIB=../lab4.a

$(ODIR)/$(PRINCIPAL).o:$(PRINCIPAL).cpp
	$(CC) $(CCFLAGS) -c $< -o $@

# cada .o depende de su .cpp
# $@ se expande para tranformarse en el objetivo
# $< se expande para tranformarse en la primera dependencia
$(ODIR)/%.o: $(CPPDIR)/%.cpp $(HDIR)/%.h
	$(CC) $(CCFLAGS) -c $< -o $@

$(LIB):$(ODIR)/$(PRINCIPAL).o $(OS)
	ar -qc $@ $^

# $^ se expande para tranformarse en todas las dependencias
$(EJECUTABLE): $(ODIR)/$(PRINCIPAL).o $(OS)
	$(CC) $(CCFLAGS) $^ -o $@

clean:
	rm -f $(EJECUTABLE) $(ODIR)/$(PRINCIPAL).o $(OS) $(LIB)

rebuild:
	make clean
	make
