a.out:DistanceClass.cpp Main.cpp Minkowski.cpp Canberra.cpp Chebyshev.cpp Manhattan.cpp Euclidean.cpp ReadFile.cpp Classification.cpp Knn.cpp Server.cpp Client.cpp
	g++ -pthread -o client.out DistanceClass.cpp MainClient.cpp Minkowski.cpp Canberra.cpp Chebyshev.cpp Manhattan.cpp Euclidean.cpp ReadFile.cpp Classification.cpp Knn.cpp Server.cpp Client.cpp Command.cpp DefaultIO.cpp StandardIO.cpp SocketIO.cpp SettingsCommandServer.cpp SettingsCommandClient.cpp UploadCommandServer.cpp UploadCommandClient.cpp ExitCommandClient.cpp ExitCommandServer.cpp ClassifyCommandServer.cpp ClassifyCommandClient.cpp DisplayCommandServer.cpp DisplayCommandClient.cpp -std=c++11
	g++ -pthread -o server.out DistanceClass.cpp MainServer.cpp Minkowski.cpp Canberra.cpp Chebyshev.cpp Manhattan.cpp Euclidean.cpp ReadFile.cpp Classification.cpp Knn.cpp Server.cpp Client.cpp Command.cpp SocketIO.cpp SettingsCommandServer.cpp SettingsCommandClient.cpp StandardIO.cpp Data.cpp DefaultIO.cpp UploadCommandServer.cpp UploadCommandClient.cpp ExitCommandClient.cpp ExitCommandServer.cpp ClassifyCommandServer.cpp ClassifyCommandClient.cpp DisplayCommandServer.cpp DisplayCommandClient.cpp -std=c++11