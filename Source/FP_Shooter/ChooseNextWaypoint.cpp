// Fill out your copyright notice in the Description page of Project Settings.

#include "ChooseNextWaypoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "PatrolRouteComponent.h"

EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBlackboardComponent * BlackBoardComponent = OwnerComp.GetBlackboardComponent();
	if (!BlackBoardComponent) return EBTNodeResult::Failed;
	int32 Index = BlackBoardComponent->GetValueAsInt(IndexKey.SelectedKeyName);
	auto AIOwner = OwnerComp.GetAIOwner();
	UPatrolRouteComponent * PatrolComponent = Cast<UPatrolRouteComponent>(AIOwner->GetControlledPawn()->GetComponentByClass(UPatrolRouteComponent::StaticClass()));
	if (!PatrolComponent) return EBTNodeResult::Failed;
	int32 PatrolPointsNumber = PatrolComponent->GetPatrolPoints().Num();
	if (PatrolPointsNumber == 0) return EBTNodeResult::Failed;
	BlackBoardComponent->SetValueAsObject(Waypoint.SelectedKeyName, PatrolComponent->GetPatrolPoints()[Index++ % PatrolPointsNumber]);
	
	BlackBoardComponent->SetValueAsInt(IndexKey.SelectedKeyName, Index % PatrolPointsNumber);
	//UE_LOG(LogTemp, Warning, TEXT("Execute task of UChooseNextWaypoint %i"), Index);
	return EBTNodeResult::Succeeded;
}
