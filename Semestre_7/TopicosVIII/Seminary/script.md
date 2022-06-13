# Presentation

Hello everyone, my name is Alisson and my presentation is about K-means, a clustering Algorithm.

---

# Overview (2nd slide)

The K-means is one of the most simple clustering algorithms that we know. The main idea is use the distance of points in a graphical representation to separete them in clusters and when you want to know what cluster a new datapoint belongs, you just insert the point and find the closer centroid, this centroid represents a cluster of the dataset, so we can see the cluster that the new datapoint belongs.

It's necessary know well the database to determine the ideal number of centroids (who is represented by the "k") and sometimes we don't know how much centroids we'll need. In this case, we can use the elbow method, so we going to learn more about it later.

I put in the presentation this maybe because if it's not me explaining it in english, maybe it will be easy. But this is not case.

---

# How it works (3th slide)

Firs, we define "k" centroids randomly into the dataset. I saw some methods that use the position of existing points selected randomly to be the centroids.
(Mostrar o gráfico do slide 5 e demonstrar que a posição de um centroid poderia ser qualquer um desses pontos).
Thus, each datapoint will be associated with a centroid. Represented by our "C" array.
After, the position of each centroid is updated based in the position of the points associated to it.
This iteration is repeated until the members of each cluster no longer change.

---

# The Algorithm (4th slide)

Here, we have the "X" representing the data and K representing the centroids.
For each datapoint in "X", the "C" array will receive the cluster id (0,1,2, etc) in the index of each "X" datapoint. This is the step where we assign the "X" datapoint to the closest centroid.
Thus, for each centroid we update the centroids with the average of the points associated to them.

---

# Example (5th slide)

Now, we have an example. 15 points were drawn here in geogebra.

---

# Example (6th slide)

After, were drawn 2 points to be the initials centroids.

---

# Example (12nd slide)

The first iteration was done. The idea is keep doing this iterations until the ‘C’ array no longer changes
Distributing the data points between the centroids again.
As there were no changes in the clusters, the final position of the centroids is there.

---

# K-means clustering using scikit-learn (13rd slide)

Now we'll see the Kmeans Method in Scikit-learn.
Here, we have the parameters and the default values of them.

---

# Example (18rd slide)

Here, we have the same example that the geogebra example.

---

# The Elbow method (19rd slide)

In this code, we're testing the Kmeans for a range of numbers of clusters.
So, the "inertia" is save in the distorsions array. Plotting the graph, we can see the "Elbow", and the number in elbow is a good number of clusters.

---

# Examples

Now, let's see the examples in colab.

The first example is the same that the Geogebra example.

---

In the second example, we have a dataset of Instagram visitors. I got this dataset from kaggle and there's no description about it. So it was the only dataset with 2 features I found. In this dataset we have the instagram visit score and the spending rank.

---

So, lets to the assessment.
