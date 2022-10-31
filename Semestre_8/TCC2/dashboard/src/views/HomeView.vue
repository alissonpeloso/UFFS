<script setup>
import RadarGraphVue from '../components/RadarGraph.vue';
</script>

<template>
	<main class="h-100">
		<div class="container-fluid h-100 d-flex flex-column">
			<div class="row m-0 py-4 ps-4 h-auto">
				<h3 class="fw-normal">
					WDOFUT
				</h3>
			</div>
			<div class="row flex-fill">
				<div class="col-3">
					<RadarGraphVue />
				</div>

				<div class="col-6">
					1
				</div>

				<div class="col-3">
					2
				</div>
			</div>
		</div>
	</main>
</template>
